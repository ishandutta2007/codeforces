n=int(input())
a=[1,5,10,20,100,n+1]
f=0
for i in range(5):
    f+=(n%a[i+1])//a[i]
    n-=(n%a[i+1])//a[i]*a[i]
print(f)