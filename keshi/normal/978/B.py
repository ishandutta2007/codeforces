n=int(input())
s=input()
f=0
for i in range(n-2):
    if s[i:i+3]==3*'x':
        f+=1
print(f)