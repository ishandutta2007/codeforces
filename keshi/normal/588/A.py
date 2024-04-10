n=int(input())
a=n*[0]
for i in range(n):
    a[i]=list(map(int,input().split()))+[1]
f=0
for i in range(n):
    if a[i][2]:
        j=i+1
        while j<n and a[j][1]>a[i][1]:
            j+=1
        s=0
        for k in range(i,j):
            s+=a[k][0]
            a[k][2]=0
        f+=s*a[i][1]
print(f)