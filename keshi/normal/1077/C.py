n=int(input())
a=list(map(int,input().split()))
s=0
for i in a:
    s+=i
b=sorted(a)
f=[]
if b[-2]==s-b[-1]-b[-2]:
    for i in range(len(a)):
        if a[i]==b[-1]:
            f+=[i]
if s-2*b[-1] in a:
    if s==b[-1]*3:
        k=0
        for i in range(len(a)):
            if a[i]==s-2*b[-1]:
                if k:
                    f+=[i]
                k=1
    else:
        for i in range(len(a)):
            if a[i]==s-2*b[-1]:
                f+=[i]
f=list(set(f))
print(len(f))
e=''
for i in f:
    e+=str(i+1)+' '
print(e)