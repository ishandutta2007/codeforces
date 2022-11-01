input()
s=raw_input()
sum=0
for p,q in zip(s[1:],s):
    if p==q:
        sum+=1
print sum