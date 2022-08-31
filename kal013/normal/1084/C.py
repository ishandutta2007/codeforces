s=raw_input()
l=[]
b=False
a=0
for i in xrange(len(s)):
    if s[i]=="b":
        if a!=0:
            l.append(a)
        a=0
    elif s[i]=="a":
        a+=1
if a!=0:
    l.append(a)
s=1 
for i in l:
    s*=(i+1)
print (s-1)%(10**9+7)