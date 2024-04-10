input()
a=list(map(int,input().split()))
f=s=0
for i in a:
    if i==-1:
        if f:
            f-=1
        else:
            s+=1
    else:
        f+=i
print(s)