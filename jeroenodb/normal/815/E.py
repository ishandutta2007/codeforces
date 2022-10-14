import functools

n,k = map(int,input().split())

def countS(b, total):
    @functools.lru_cache(maxsize=None)
    def solve(v):
        if (v-1)//2<b:
            return 0
        return 1+solve((v-1)//2)+solve(v//2)
    return solve(total)

if k==1:
    print(1)
    exit()
elif k==2:
    print(n)
    exit()

lo,hi = 0,n-1
while lo<hi:
    mid = (lo+hi+1)//2
    if countS(mid,n-2)+2>=k:
        lo = mid
    else:
        hi = mid-1

V = lo
k-=countS(V+1,n-2)+2 # all things bigger than it

@functools.lru_cache(maxsize=None)
def solve(v):
    if (v-1)//2<V:
        return 0
    if v==0:
        return 1
    return ((v-1)//2==V) + solve((v-1)//2)+solve(v//2)

def findPlace(len, k):
    if (len-1)//2==V and k==1:
        return (len-1)//2
    if (len-1)//2==V:
        k-=1
    tmp = solve((len-1)//2)
    if tmp>=k:
        return findPlace((len-1)//2,k)
    k-=tmp
    return (len+1)//2 + findPlace(len//2,k)

print(findPlace(n-2,k)+2)