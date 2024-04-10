input()
a=list(map(int,input().split()))
s=0
for i in a:
    s+=i
print(s/len(a))