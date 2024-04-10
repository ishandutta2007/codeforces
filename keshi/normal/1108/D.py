n=int(input())
f=["R","G","B"]
s=list(input())
i=1
x=0
while i<len(s)-1:
    if s[i]==s[i-1]:
        h=f[:]
        h.remove(s[i-1])
        if s[i+1] in h:
            h.remove(s[i+1])
        s[i]=h[0]
        i+=1
        x+=1
    i+=1
if n>1 and s[-1]==s[-2]:
    h=f[:]
    h.remove(s[-1])
    s[i]=h[0]
    x+=1
print(x)
d=''
for i in s:
    d+=i
print(d)