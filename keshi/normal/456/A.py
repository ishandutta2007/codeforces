n=int(input())
a=n*[0]
for i in range(n):
    a[i]=list(map(int,input().split()))
a.sort()
f=1
for i in range(1,n):
    if a[i][1]<a[i-1][1]:
        print("Happy Alex")
        f=0
        break
if f:
    print("Poor Alex")