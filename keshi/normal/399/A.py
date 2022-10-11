n,x,k=map(int,input().split())
s=''
if x>k+1:
    s+='<< '
for i in range(max(1,x-k),min(n,x+k)+1):
    if i==x:
        s+="("+str(i)+") "
    else:
        s+=str(i)+' '
if x+k<n:
    s+='>>'
print(s)