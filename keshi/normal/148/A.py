a=4*[0]
for i in range(4):
    a[i]=int(input())
n=int(input())
s=0
for i in range(1,n+1):
    f=0
    for j in range(4):
        if i%a[j]==0:
            f=1
            break
    if f:
        s+=1
print(s)