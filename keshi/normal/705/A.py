n=int(input())
s='that I '
a=['hate ','love ']
f=''
for i in range(n):
    f+=s+a[i%2]
f+='it'
f=f[5:]
print(f)