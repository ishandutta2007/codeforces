f=["R","G","B"]
n=int(input())
s=input()
b=n*[0]
for i in range(len(s)):
    if s[i]=="R":
        b[i]=0
    elif s[i]=="G":
        b[i]=1
    else:
        b[i]=2
d=[[0,1,2],[0,2,1],[1,0,2],[1,2,0],[2,0,1],[2,1,0]]
r=[]
for i in range(len(d)):
    g=0
    for j in range(len(b)):
        if b[j]!=d[i][j%3]:
            g+=1
    r+=[g]
    if g==0:
        break
p=min(r)
e=d[r.index(p)]
print(p)
q=''
for i in range(n):
    q+=f[e[i%3]]
print(q)