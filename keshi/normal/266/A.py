input()
s=input()
n=0
for i in range(1,len(s)):
    if s[i]==s[i-1]:
        n+=1
print(n)