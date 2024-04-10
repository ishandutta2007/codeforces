n=int(input())
a=list(map(int,input().split()))
for i in range(1,n+1):
    print(a.index(i)+1,end=' ')