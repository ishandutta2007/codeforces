n,m=map(int,input().split())
a=list(map(int,input().split()))
b=n*[0]
p=0
s=''
for i in a:
    if not b[i-1]:
        p+=1
    b[i-1]+=1
    if p==n:
        p=0
        for i in range(n):
            b[i]-=1
            if b[i]:
                p+=1
        s+='1'
    else:
        s+='0'
print(s)