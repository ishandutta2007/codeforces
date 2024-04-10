def get():
    return list(map(int,input().split()))
n=int(input())
a=get()
xor=(n+1)*[0]
for i in range(1,n+1):
    xor[i]=xor[i-1]^a[i-1]
ans=0
b=[{},{}]
for i in range(2):
    for j in range(i,n+1,2):
        if not xor[j] in b[i]:
            b[i][xor[j]]=0
        ans+=b[i][xor[j]]
        b[i][xor[j]]+=1
print(ans)