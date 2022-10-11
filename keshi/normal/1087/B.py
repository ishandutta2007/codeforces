a=list(map(int,input().split()))
f=0
for i in range(a[1]-1,0,-1):
    if not a[0]%i:
        print(a[1]*(a[0]//i)+i)
        break