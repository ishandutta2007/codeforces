n=int(input())
a=n*[0]
for i in range(n):
    a[i]=int(input())
q=[[0,0]]
f=0
while q:
    w=q.pop(0)
    if w[0]==n and w[1]%360==0:
        f=1
        break
    if w[0]!=n:
        q=[[w[0]+1,w[1]+a[w[0]]]]+q
        q=[[w[0]+1,w[1]-a[w[0]]]]+q
if f:
    print("YES")
else:
    print("NO")