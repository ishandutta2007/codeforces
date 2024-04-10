n=int(input())
m=int(input())
h=m
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if 1 in a or 1 in b:
    print(-1)
else:
    for i in range(n):
        m+=m/(a[i]-1)
        m+=m/(b[i]-1)
    print(m-h)