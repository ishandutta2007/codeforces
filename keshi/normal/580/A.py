n=int(input())
a=list(map(int,input().split()))
l=0
s=0
i=0
for i in range(1,len(a)):
    if a[i]<a[i-1]:
        if i-l>s:
            s=i-l
        l=i
if i-l+1>s:
    s=i-l+1
print(s)