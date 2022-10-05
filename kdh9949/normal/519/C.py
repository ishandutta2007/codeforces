s=input()
i=0
while s[i]!=' ':
    i=i+1
a=int(s[:i])
b=int(s[i+1:])
c=0
while a!=0 and b!=0:
    if a==1 and b==1:
        break
    if a<b:
        a=a-1
        b=b-2
    else:
        a=a-2
        b=b-1
    c=c+1
print(c)