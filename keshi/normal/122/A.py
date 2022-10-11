n=int(input())
a=[4,7,44,47,74,77,444,447,474,477,744,747,774,777]
f="NO"
for i in a:
    if n%i==0:
        f="YES"
        break
print(f)