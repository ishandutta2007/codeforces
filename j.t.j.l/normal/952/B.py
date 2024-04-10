import sys

f=['great', 'think', 'bad', 'cool', 'touch']
g=['even', 'serious', 'worse', 'terrible', 'die', 'way']

flag = 0
for i in range(10000):
    print(i%10)
    sys.stdout.flush()
    s=input()
    for x in f:
        if (s.find(x) >= 0) and flag == 0:
            print('normal')
            flag = 1
            break
    for x in g:
        if (s.find(x) >= 0) and flag == 0:
            print('grumpy')
            flag = 1
            break
    if flag == 1:
        break
sys.stdout.flush()