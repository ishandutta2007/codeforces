a=3*[0]
for i in range(3):
    a[i]=int(input())
print(max(a[0]+a[1]+a[2],a[0]*a[1]+a[2],a[0]*a[1]*a[2],a[0]+a[1]*a[2],(a[0]+a[1])*a[2],a[0]*(a[1]+a[2])))