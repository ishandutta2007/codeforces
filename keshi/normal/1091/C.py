n=int(input())
s=[]
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        s=[(n-i+2)*(n//i)//2]+s
        if i*i!=n:
            i=n//i
            s=[(n-i+2)*(n//i)//2]+s
s.sort()
for i in  s:
    print(i,end=' ')
'''for j in range(1,n//2):
    j=j*2
    if n%j==0:
        s=[(n-j+2)*(n//j)//2]+s
i=3
while i<=n:
    f=1
    for d in a:
        if i%d==0:
            f=0
    if f:
        a+=[i]
    i+=1
print(a)
for i in range(1,n//2+1):
    if n%i==0:
        s=[(n-i+2)*(n//i)//2]+s
s=[1]+s
print(1)
s=[1]+s+[(n+1)*n//2]
for i in  s:
    print(i,end=' ')
'''