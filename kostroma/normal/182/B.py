
def solve():
    d=int(raw_input())
    n=int(raw_input())
    s=0
    a=[ int(x) for x in raw_input().split()]
    for i in range(0, n-1):
        a[i]=d-a[i]
        s+=a[i]
    print s
if __name__ == "__main__":
    solve()