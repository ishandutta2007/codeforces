a=list(map(int,input().split()))
x=0
for i in range(a[0]+1):
    if a[1]>=i+1 and a[2]>=i+2:
        x=i*3+3
print(x)