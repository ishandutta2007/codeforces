a,b=map(int,input().split())
s=list(map(int,input().split()))
l=1
f=0
for i in s:
    f+=(i-l)%a
    l=i
print(f)