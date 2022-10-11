a=input()
while "WUB" in a:
    n=a.index("WUB")
    a=a[:n]+' '+a[n+3:]
b=a.split()
s=''
for i in b:
    s+=i+' '
print(s)