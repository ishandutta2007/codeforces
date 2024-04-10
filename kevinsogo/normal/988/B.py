s = sorted((input() for i in range(int(input()))), key=len)
if all(x in y for x, y in zip(s, s[1:])):
    print('YES', *s, sep='\n')
else:
    print('NO')