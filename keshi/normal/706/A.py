x,y=map(int,input().split())
n=int(input())
a=list(map(int,input().split()))
m=(abs(a[0]-x)**2+abs(a[1]-y)**2)**0.5/a[2]
for i in range(n-1):
    a=list(map(int,input().split()))
    m=min(m,(abs(a[0]-x)**2+abs(a[1]-y)**2)**0.5/a[2])
print(m)