n=input()
a=[0]*5
for i in map(int,raw_input().split()):
    a[i]+=1
print a[4]+a[3]+(a[2]/2)+(max(0,a[1]-a[3])+3+(a[2]&1)*2)/4