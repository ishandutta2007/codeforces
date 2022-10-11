a,b=map(int,input().split())
l=list(map(int,input().split()))
f=list(set(l))
s=len(f)*[0]
for i in range(len(s)):
    s[i]=[]
h=a*[0]
o=a*[1]
for i in range(b):
    for j in range(len(l)):
        if o[j] and not (i+1) in s[f.index(l[j])]:
            s[f.index(l[j])]+=[i+1]
            h[j]=i+1
            o[j]=0
            break
for i in range(len(l)):
    if not h[i]:
        for j in range(1,b+1):
            if not j in s[f.index(l[i])]:
                s[f.index(l[i])]+=[j]
                h[i]=j
                break
q=1
for i in h:
    if not i:
        q=0
        break
if q:
    print("YES")
    s=''
    for i in h:
        s+=str(i)+' '
    print(s)
else:
    print("NO")