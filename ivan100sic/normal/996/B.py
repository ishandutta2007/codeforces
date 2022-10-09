n=int(input())
a=list(map(int,input().split()))
x=min(a)//n*n
s=x
for i in range(n):
    a[i]-=x
for i in range(2*n):
    if a[i%n]<=i:
        print(i%n+1)
        exit()