n=int(input())
for i in range(n):
    a,b,k=list(map(int,input().split()))
    print(a*((k+1)//2)-b*(k//2))