n,p,q=map(int,raw_input().split())
p,q=min(p,q),max(p,q)
ca=n//p+1
cb=0
s=raw_input()
flag=False

while ca>=0:
    while ca*p+cb*q<n:
        cb+=1 
    
    if (ca*p+cb*q==n):
        flag=True
        break
    ca-=1 
if not flag:
    print -1 
else:
    print ca+cb 
    i=0
    while (i<n):
        if ca>0:
            print s[i:i+p]
            i+=p 
            ca-=1 
        else:
            print s[i:i+q]
            i+=q 
            cb-=1