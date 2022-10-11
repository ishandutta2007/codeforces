def get():
    return list(map(int,input().split()))
n=int(input())
for i in range(n):
    a=get()
    s=a[0]
    if a[0]==a[2]:
        if a[3]>a[2]:
            d=a[2]+1
        else:
            s+=1
            d=a[2]
    else:
        d=a[2]
    print(s,d)