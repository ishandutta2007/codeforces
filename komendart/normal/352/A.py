input()
a = input().split()

zero, five = a.count('0'), a.count('5')

if zero == 0:
    print("-1")
elif five < 9:
    print("0")
else:
    for i in range(five - five % 9):
        print('5', end='')
    for i in range(zero):
        print('0', end='')
    print()