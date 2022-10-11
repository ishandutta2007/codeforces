n=int(input())
a=list(map(int,input().split()))
s=sum(a)
m=0
for i in range(n):
    for j in range(i,n):
        b=a[i:j+1]
        c=b.count(0)-b.count(1)
        if c+s>m:
            m=c+s
print(m)