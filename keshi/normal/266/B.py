n,s=map(int,input().split())
a=list(input())
for i in range(s):
    j=0
    while j<n-1:
        if a[j]=="B" and a[j+1]=="G":
            a[j],a[j+1]=a[j+1],a[j]
            j+=1
        j+=1
for i in a:
    print(i,end='')