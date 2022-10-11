s,n=map(int,input().split())
a=n*[0]
for i in range(n):
    a[i]=list(map(int,input().split()))
a.sort()
f=1
for i in range(len(a)):
    if s>a[i][0]:
        s+=a[i][1]
    else:
        print("NO")
        f=0
        break
if f:
    print("YES")