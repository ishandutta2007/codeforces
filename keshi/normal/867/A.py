n=int(input())
f=0
a=input()
for i in range(1,n):
    if a[i]!=a[i-1]:
        if a[i]=="F":
            f+=1
        else:
            f-=1
if f>0:
    print("YES")
else:
    print("NO")