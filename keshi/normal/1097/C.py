def check(s):
    f=0
    for i in s:
        if i=='(':
            f+=2
        f-=1
        if f<0:
            return 0
    return 1
def check2(s):
    f=0
    for i in s:
        if i=='(':
            f+=2
        f-=1
        if f>0:
            return 0
    return 1
n=int(input())
a={}
b={}
c=0
for i in range(n):
    s=input()
    if check(s) or check2(s[::-1]):
        x=s.count('(')-s.count(')')
        if x<0:
            if x in b:
                b[x]+=1
            else:
                b[x]=1
        elif x>0:
            if x in a:
                a[x]+=1
            else:
                a[x]=1
        else:
            c+=1
f=c//2
for i in list(a):
    if -i in b:
        f+=min(a.get(i),b.get(-i))
print(f)