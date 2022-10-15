import sys
input=sys.stdin.readline
l=input().split()
n=int(l[0])
k=int(l[1])
l=input().split()
li=[int(i) for i in l]
curr=0
haveto=0
ans=0
for i in range(n):
    curr+=li[i]
    z=max((haveto+k-1)//k,curr//k)
    curr=max(curr-k*z,0)
    haveto=curr
    ans+=z
ans+=((haveto+k-1)//k)
print(ans)