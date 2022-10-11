a=list(map(int,input().split()))
s=sum(a)
if s%2:
    print("NO")
else:
    s//=2
    f=0
    for i in range(6):
        for j in range(i+1,6):
            for k in range(j+1,6):
                if a[i]+a[j]+a[k]==s:
                    print("YES")
                    f=1
                    break
            if f:
                break
        if f:
            break
    if not f:
        print("NO")