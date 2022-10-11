n=int(input())
a=list(map(int,input().split()))
a.sort()
print(min(a[-2]-a[0],a[-1]-a[1]))