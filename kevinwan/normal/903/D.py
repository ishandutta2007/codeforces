import sys
input=sys.stdin.readline
n=int(input())
a=map(int,input().split())
d={}
ans=sum=num=0
for x in a:
    t=x*num-sum
    if x-1 not in d:
        d[x-1]=0
    if x+1 not in d:
        d[x+1]=0
    if x not in d:
        d[x]=0
    t-=d[x-1]
    t+=d[x+1]
    d[x]+=1
    num+=1
    sum+=x
    ans+=t
print(ans);