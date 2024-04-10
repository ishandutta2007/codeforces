n=int(input())
a=list(map(int,input().split()))
f=0
b=[]
for i in range(1,n-1):
    if a[i]==0 and a[i-1] and a[i+1]:
        b+=[i]
k=0
for i in range(len(b)-1):
    if b[i+1]!=b[i]+2 or k:
        f+=1
        k=0
    else:
        k=1
if b:
    f+=1
print(f)