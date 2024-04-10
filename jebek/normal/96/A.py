s=raw_input()
a="0"*7
b="1"*7
ans="NO"
for i in range(len(s)-6):
    if s[i:i+7]==a or s[i:i+7]==b :
        ans="YES"
print ans