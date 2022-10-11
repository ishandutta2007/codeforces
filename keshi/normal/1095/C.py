e,b=map(int,input().split())
s=[]
d=[]
a=e
while a:
    s+=[a%2]
    a=a//2
for i in range(len(s)):
    if s[i]:
        d+=[2**i]
if b>e or len(d)>b:
    print("NO")
elif e==b:
    print("YES")
    print(e*'1 ')
else:
    i=0
    while i<len(d) and len(d)!=b:
        if d[i]!=1:
            d+=[d[i]//2,d[i]//2]
            d.pop(i)
        else:
            i+=1
    print("YES")
    d.sort()
    s=''
    for i in d:
        s+=str(i)+' '
    print(s)