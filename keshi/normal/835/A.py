a=list(map(int,input().split()))
if 2*a[3]+a[0]*a[1]>2*a[4]+a[0]*a[2]:
    print("Second")
elif 2*a[3]+a[0]*a[1]<2*a[4]+a[0]*a[2]:
    print("First")
else:
    print("Friendship")