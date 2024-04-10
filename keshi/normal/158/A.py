n,m=map(int,input().split())
a=list(map(int,input().split()))
h=a[m-1]
m=0
while m<len(a) and a[m]>0 and a[m]>=h:
    m+=1
print(m)