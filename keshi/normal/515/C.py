n=int(input())
s=list(input())
while '1' in s:
    s.remove('1')
while '0' in s:
    s.remove('0')
b=[['9',['7','3','3','2']],['8',['7','2','2','2']],['6',['5','3']],['4',['2','2','3']]]
for i in range(4):
    while b[i][0] in s:
        s.remove(b[i][0])
        s+=b[i][1]
s.sort(reverse=1)
g=''
for i in s:
    g+=i
print(g)