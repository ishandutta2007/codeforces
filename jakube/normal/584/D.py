from math import sqrt; from itertools import count, islice

def isPrime(n):
    if n < 2: return False
    return all(n%i for i in islice(count(2), int(sqrt(n)-1)))

number = int(input())
if number < 9:
    print(1)
    print(number)
else:
    number2 = number - 6
    while not isPrime(number2):
        number2 -= 2

    difference = number - number2
    for i in range(1, difference, 2):
        if isPrime(i) and isPrime(difference - i):
            print(3)
            print(' '.join(map(str, [i, difference - i, number2])))
            break