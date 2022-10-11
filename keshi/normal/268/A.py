n=int(input())
a=n*[0]
b=n*[0]
for i in range(n):
    a[i],b[i]=map(int,input().split())
f=0
for i in range(n):
    f+=b.count(a[i])+a.count(b[i])
print(f//2)