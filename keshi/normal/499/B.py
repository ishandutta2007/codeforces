n,m=map(int,input().split())
a=[]
for i in range(m):
    b=input().split()
    if len(b[1])<len(b[0]):
        b.reverse()
    a+=b
s=input().split()
d=''
for i in s:
    d+=a[a.index(i)//2*2]+' '
print(d)