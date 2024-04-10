d={}
d['polycarp'], h=1, 1
n = int(input())
for i in range(0, n):
    a,b,c=input().lower().split()
    d[a]=d[c]+1
print (max(d.values()))