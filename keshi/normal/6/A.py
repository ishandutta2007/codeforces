a=list(map(int,input().split()))
f=0
for i in range(4):
    b=a[:i]+a[i+1:]
    b.sort()
    if b[0]+b[1]>b[2]:
        f=1
    elif b[0]+b[1]==b[2]:
        f=2
    if f==1:
        print("TRIANGLE")
        break
if f==2:
    print("SEGMENT")
elif f==0:
    print("IMPOSSIBLE")